
$trigger = New-ScheduledTaskTrigger -Daily -At 12:00        
$Action = New-ScheduledTaskAction -Execute "PowerShell.exe" -Argument '' -WorkingDirectory "D:\Universidade\2 ano\labinfo\"
Register-ScheduledTask -TaskName "Teste2" -Trigger $trigger -Action $action 



