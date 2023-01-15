The tests here require PowerShell 7.4.0 Preview 1. The Preview 1 has $PSNativeCommandUseErrorActionPreference set to $true
by default. Looking like $PSNativeCommandUseErrorActionPreference many be set to $false by default in supsequent releases.
You might or might not get same resuslt that I am seeing using 7.4.0 released version or newer by making sure 
that $PSNativeCommandUseErrorActionPreference is set to $true.