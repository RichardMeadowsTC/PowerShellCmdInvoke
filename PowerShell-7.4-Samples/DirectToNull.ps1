# This is supposed to also workaround issue with pwsh.exe raising an error when exe returns non-zero.

$ErrorActionPreference = 'Continue'

# Setting PSNativeCommandUseErrorActionPreference true incase it gets defaulted to $false in subsequent releases.
$PSNativeCommandUseErrorActionPreference = $true
# This just hides the error stream.
.\ErrorSimulator.exe /return:3 2>$null

# Confirm are getting an excption raised.
$ErrorActionPreference = 'Stop'
.\ErrorSimulator.exe /return:3 2>$null