<?php
session_start();

$con= mysqli_connect("localhost", "root", "","feedback");

if(!$con)
{
die("Server could not connected");
}
 
if(isset($_POST["btn"]))
{
$name=$_POST["name"];
$feed=$_POST["feed"];

$sql="INSERT into feed (name,feed)Values('".$name."','".$feed."')";
$n=mysqli_query($con,$sql);
}
?>
<!DOCTYPE html>
<html>
<head>
<title>Feedback | Jamsheed |</title>
</head>
<script>

function check()
{
alert('Thank you for your feedback.');
}
</script>
<div class="container">
<form id="contact" action="" method="post">
<h3>Feedback Form</h3>
<h4>"The key to learning is feedback.It is nearly impossible to learn anything with out it"</h4>
<fieldset>
    <legend>Hello</legend>
<input placeholder="Your name" type="text" name="name" tabindex="1" required autofocus>
</fieldset>
<fieldset>
<textarea placeholder="Write Something about me.." name="feed" tabindex="5" required autofocus></textarea>
</fieldset>
<fieldset>
<input type="submit" name="btn" value="Submit" onclick="check()">
</fieldset>
</form>
</div>

<?php
// connect to mysql
$conn= mysqli_connect("localhost", "root", "","feedback");
if(! $conn )
{
die('Could not connect: ' );
}

$sql = 'SELECT name,feed FROM feed';

$n=mysqli_query($conn,$sql);
if(!$n )
{
die('Could not get data: ');
}
while($row = mysqli_fetch_array($n, MYSQLI_ASSOC))
{
echo "{$row['name']} ". " : {$row['feed']} <br> ";
}

mysqli_close($conn);
?>

</body>
</html>
