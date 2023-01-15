
# This shows that error code of app ran in cmd.exe process is returned to the caller.
# Different than PowerShell.  With PowerShell you have to force the process to exit with specifed code.
Invoke-Expression 'cmd.exe /c "ErrorSimulator.exe /return:10"'