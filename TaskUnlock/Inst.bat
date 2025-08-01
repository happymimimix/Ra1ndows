copy "%~dp0RTCore64.sys" "C:\Windows\System32\drivers\RTCore64.sys" /v /y
SC create RTCore64 type=kernel start=auto binPath="C:\Windows\System32\drivers\RTCore64.sys" DisplayName="PPL CONTROL"
net start RTCore64
pause