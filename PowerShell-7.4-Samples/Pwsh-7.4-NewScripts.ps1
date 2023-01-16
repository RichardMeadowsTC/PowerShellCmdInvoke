# Should scope use of PSNativeCommandUseErrorActionPreference in new projects.

$ErrorActionPreference = 'Stop'

# Setting PSNativeCommandUseErrorActionPreference true incase it gets defaulted to $false in subsequent releases.
$PSNativeCommandUseErrorActionPreference = $true

# Use script block to create a new scope and modify PSNativeCommandUseErrorActionPreference for a short time.
& {
    $PSNativeCommandUseErrorActionPreference = $false
    .\ErrorSimulator.exe /return:1
}

# This one should report error
.\ErrorSimulator.exe /return:11