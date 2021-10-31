Copy-Item -Filter *. C:\Users\MoonShadow\Documents\teste D:\ 

$MailFrom='that1guywssc@gmail.com'
$MailTo='joao.diogo.machado@gmail.com'
$SmtpServer='smtp.gmail.com' 
$Body="Mensagem que pretendemos mandar"
$Subject='Mensagem do assunto do mail'


Send-MailMessage -From "$MailFrom" -To "$MailTo" -SmtpServer "$SmtpServer" -Body "$Body" -Subject "$Subject" -Credential (Get-Credential) -UseSsl