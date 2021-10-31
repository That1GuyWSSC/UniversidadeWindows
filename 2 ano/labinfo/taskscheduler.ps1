$acao = (New-ScheduledTaskAction -Execute 'D:\Universidade\2 ano\labinfo\emailbat.bat') 
$trigger = New-ScheduledTaskTrigger -Daily -At '10:00 AM'
$principal = New-ScheduledTaskPrincipal -UserId 'MSI\MoonShadow' -RunLevel Highest
$definicoes = New-ScheduledTaskSettingsSet -RunOnlyIfNetworkAvailable -WakeToRun
$task = New-ScheduledTask -Action $acao -Principal $principal -Trigger $trigger -Settings $definicoes
Register-ScheduledTask 'Copias de Seguranca + Email' -InputObject $task 


$acao2 = (New-ScheduledTaskAction -Execute 'D:\Universidade\2 ano\labinfo\pcbat.bat') 
$trigger = New-ScheduledTaskTrigger -Weekly -DaysOfWeek Wednesday -At '10:00 AM'
$definicoes2 = New-ScheduledTaskSettingsSet -RunOnlyIfNetworkAvailable -WakeToRun
$principal = New-ScheduledTaskPrincipal -UserId 'MSI\MoonShadow' -RunLevel Highest
$task = New-ScheduledTask -Action $acao2 -Principal $principal -Trigger $trigger -Settings $definicoes2
Register-ScheduledTask 'Informacao sobre o computador' -InputObject $task 

