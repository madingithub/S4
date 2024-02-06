Create Cookies <br>
<?php
setcookie("username","guru",time()+(83400*30),"/");
?>


Retrieving Cookies Value <br>

<?php
echo $_COOKIE['username']
?>