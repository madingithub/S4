<!DOCTYPE html>
<html>
<head>
    <title>Programme</title>
</head>
<body>
    <form action="" method="post">
        <label for="name">Enter Your Name</label><br>
        <input type="text" name="name" id="name"><br>

        <label for="pass">Enter Your Password</label><br>
        <input type="password" name="pass" id="pass"><br>

        <input type="submit">

    </form>
    <?php
    $name=$_POST["name"];
    $pass=$_POST["pass"];
    echo "You Have Entered Your Details";
    ?>
</body>
</html>