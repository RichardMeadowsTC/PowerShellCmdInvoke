
# Make sure PSNativeCommandUseErrorActionPreference is true incase it gets defaulted to false in supsequent releases.
$PSNativeCommandUseErrorActionPreference = $true

# This does not cause PS 7.4 to raise an error when $PSNativeCommandUseErrorActionPreference is $true
# Can verify ErrorSimulator.exe is working correctly by running the following in cmd.exe shell
# ErrorSimulator.exe /stream:stderr 2>out.txt
# ErrorSimulator.exe /stream:stdout 2>out.txt
.\ErrorSimulator.exe /stream:stderr