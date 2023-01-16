Random prototypes of ideas for wrappers that invoke EXEs from in PowerShell scripts.
Seams with version 7.4 they are bringing changes that cause error records to be
generated when the EXE returns non-zero. And I am not sure yet, but might 
also generate an error record when the EXE writes to stderr.

There is a setting to control the new / changed behaviour, $PSNativeCommandUseErrorActionPreference
When it is true, powershell will raise an error when native app returns non-zero exit code.
Have to set it false to keep the original behaviour. Ignoring the return code. Unless there script
added to check $LASTEXITCODE