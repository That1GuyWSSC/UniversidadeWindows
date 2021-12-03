echo "##Informacao sobre o processador##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
Get-CimInstance -Class Win32_Processor | Out-File C:\Users\MoonShadow\Desktop\cenas2.txt

 # ComputerSystem info
 echo "##Informacao sobre o nome do computador##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
 Get-CimInstance Win32_ComputerSystem | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt

 # OS info
 echo "##Informacao sobre o sistema operativo##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
 Get-CimInstance Win32_OperatingSystem  | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt

# Serial No
echo "##Informacao sobre a bios##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
 Get-CimInstance Win32_BIOS  | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt

 # CPU Info
 echo "##Mais Informacao sobre o processador##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_Processor | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
  
  echo "##Informacao sobre utilizadores no computador##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_SystemAccount  | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt

  echo "##Informacao sobre os discos##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_DiskDrive   | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
  
  echo "##Mais Informacao sobre as particoes dos discos##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_DiskPartition   | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
  
  echo "##Informacao sobre as placas graficas##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_VideoController  | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
  
  echo "## Informacao sobre adaptadores de rede##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_NetworkAdapter  | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
  
  echo "##Todos os servicos a correr no momento no computador##" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  Get-CimInstance Win32_Service    | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
  
  echo "Informacao sobre a rede do computador" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  ipconfig.exe | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt
 


 
 
  # Computer Info
  #Get-ComputerInfo | Format-List | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt

  # Getting Permisssions for all user
  #echo "Permissoes para todos os utilizadores" >> C:\Users\MoonShadow\Desktop\cenas2.txt
  #Get-acl -path hklm:\system\currentcontrolset\control | Add-Content C:\Users\MoonShadow\Desktop\cenas2.txt


  



