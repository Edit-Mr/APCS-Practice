# Get the current directory
$currentDirectory = Get-Location

# Find all .exe files in the current directory
$exeFiles = Get-ChildItem -Path $currentDirectory -Filter *.exe

# Loop through each .exe file and delete it
foreach ($file in $exeFiles) {
    Remove-Item -Path $file.FullName -Force
}

# Optional: Output a message indicating completion
Write-Output "All .exe files have been deleted from the current folder."
