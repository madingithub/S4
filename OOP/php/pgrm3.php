<html>
<head>
<title> Find out odd or even number. . ! </title>
</head >
<body>
    <form action="" method="post">
            Enter a number:
            <input type=text name="t1">
            <br>
            <br>
            <input type=submit name="s">
<?php
$a =$_POST['t1'];
if ($a % 2==0)
{
echo "Given number is" . "<br>" . "<b>EVEN<b>" ;
}
else
{
echo "Given number is" . "<br>" . "<b>ODD<b>";
}
?>
</body>
</html>