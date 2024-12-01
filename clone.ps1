# 设置用户名
$username = "libdriver"

# 初始化变量
$page = 1
$perPage = 100  # 每页最多可以请求 100 个仓库
$allRepos = @() # 用于存储所有仓库信息

# 分页获取所有仓库信息
do {
    $url = "https://api.github.com/users/$username/repos?per_page=$perPage&page=$page"
    Write-Host "Fetching repositories from: $url" # 英文输出
    $repos = Invoke-RestMethod -Uri $url -Headers @{ "User-Agent" = "PowerShell" }
    $allRepos += $repos
    $page++
} while ($repos.Count -gt 0)

# 检查是否存在存储库目录，如果不存在则创建
$clonePath = Join-Path -Path (Get-Location) -ChildPath "libdriver"
if (-Not (Test-Path -Path $clonePath)) {
    New-Item -ItemType Directory -Path $clonePath
}

# 切换到存储库目录
Set-Location -Path $clonePath

# 批量克隆所有仓库
foreach ($repo in $allRepos) {
    $repoName = $repo.name
    $repoDir = Join-Path -Path $clonePath -ChildPath $repoName
    $sshUrl = $repo.ssh_url # 获取 SSH 克隆的 URL

    # 检查目录是否已经存在
    if (Test-Path -Path $repoDir) {
        Write-Host "Directory already exists, skipping: $repoName" # 英文输出
        continue
    }

    # 克隆仓库
    Write-Host "Cloning repository: $repoName ($sshUrl)" # 英文输出
    git clone $sshUrl
}
