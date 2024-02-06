<!DOCTYPE html>
<html lang="en">
<head>
    <title>File Upload</title>
</head>
<body>
    <form method="post" enctype="multipart/form-data">
    <input type="file" name="myfile">
    <input type="submit" value="upload">
    </form>
</body>
</html>

<?php
$file_name=$_FILES['myfile']['name'];
$temp=$_FILES['myfile']['tmp-name'];
$new_file_name=time() .$file_name;
move_uploaded_file($temp,"uploads/" .$new_file_name);
echo "<img src='uploads/' .$new_file_name>"
?>