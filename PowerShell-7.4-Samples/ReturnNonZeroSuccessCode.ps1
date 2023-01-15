
$ErrorActionPreference = 'Continue'

# Assuming using Pwsh.exe 7.4.0-preview1, the command will cause an error.
# $PSNativeCommandUseErrorActionPreference is set $true by default.
.\ErrorSimulator.exe /return:2

$PSNativeCommandUseErrorActionPreference = $false
.\ErrorSimulator.exe /return:2

# Make sure $PSNativeCommandUseErrorActionPreference = $false really does work.
$ErrorActionPreference = 'Stop'
.\ErrorSimulator.exe /return:2

# This shows that we do we actually get the return code.
.\ErrorSimulator.exe /return:5
$err = $LASTEXITCODE
Write-Host "Err should be 5: $err"