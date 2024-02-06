<!DOCTYPE html>
<html>
<head>
    <title>Control Statement</title>
</head>
<body>
    <?php
    $x=15;
    $y=5;
    if ($x>$y)
    {
        echo "$x is Greater Than $y <br>";
    }
    else if ($x<$y)
    {
        echo "$x is Less Than $y";
    }
    else
    {
        echo "Both Are Equal";
    }

?>

    <?php
    $x=15;
    $y=10;
    $op='*';

    switch($op)
    {
        case '+':$z=$x+$y;
        echo "Addition is: $z";
        break;

        case '-':$z=$x-$y;
        echo "Substraction is: $z";
        break;

        case '*':$z=$x*$y;
        echo "Multiplication is: $z <br>";
        break;

        case '/':$z=$x/$y;
        echo "Division is: $z";
        break;

        case '%':$z=$x%$y;
        echo "Modulus is: $z";
        break;   
    }
    ?>

    <?php
    $n=1;
    while($n<=5)
    {
        echo "$n <br>";
        $n++;
    }
        ?>

        <?php
        $n=1;
        do
        {
            echo "$n <br>";
            $n++;
        }
        while($n<=5);
        ?>

        <?php
        for($i=1;$i<=5;$i++)
        {
            echo "$i <br>";
        }
        
        ?>
</body>
</html>