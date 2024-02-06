<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    if(isset($_POST["form_submitted"])){
        if(!isset($_POST["agree"])){?>
            <p style="color:red">You have not accepted our terms and conditions</p>
        <?php } else {?>
            <h2 style="color:green">Thank you, <?php echo $_POST["firstname"];?></h2>
            <p>You have been registered as 
                <?php echo $_POST["firstname"]." ".$_POST["lastname"];?>
            </p>
            <p>Go <a href="prgm8.php">back</a> to the form</p>
        <?php }?>
    <?php } else {?>
        <h2>Registration form</h2>
        <form action="" method="POST">
            <label for="">First name</label>
            <input type="text" name="firstname"><br> <br>
            <label for="">Last name</label>
            <input type="text" name="lastname">
            <br>Agree to terms of service
            <input type="checkbox" value="agree" name="agree" id="">
            <br>
            <input type="hidden" name="form_submitedf" value="1">

            <input type="submit" name="form_submitted" value="Submit">
        </form>
    <?php }?>
</body>
</html>

