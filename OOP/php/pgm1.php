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
    $x=15;
    $y=5;
    $op='+';
    switch($op){
        case'+': $z=$x+$y;
        echo"adding is $z";
        break;
        case'-': $z=$x-$y;
        echo"substration is $z";
        break;
        case'*': $z=$x*$y;
        echo"multiplecation is $z";
        break;
        case'/': $z=$x/$y;
        echo"ditions is $z";
        break;
        case'%': $z=$x%$y;
        echo"modules is $z";
        break;
        default:
        echo"inalide opration";

    }

 ?>
</body>
</html>