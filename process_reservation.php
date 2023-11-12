<?php
// Check if the data is received from the AJAX request
if (isset($_POST['data'])) {
  $formData = json_decode($_POST['data'], true);

  // Get the values from the form data
  $boarding = $formData['boarding'];
  $destination = $formData['destination'];
  $priority = $formData['priority'];

  // Your code to set the price based on cities and class (you can modify this as needed)
  // For example, you can use an associative array to map the price based on city and class
  $price = calculatePrice($boarding, $destination, $priority);

  // Your code to insert the data into the "users" table in the database
  // Use MySQLi or PDO to connect to the database and execute the INSERT query
  // Example using MySQLi:
  $conn = new mysqli('sql202.infinityfree.com', 'if0_34593766', 'x0dPlnpAvs8', 'if0_34593766_pdetails');
  if ($conn->connect_error) {
    die('Connection failed: ' . $conn->connect_error);
  }
  $boarding = $conn->real_escape_string($boarding);
  $destination = $conn->real_escape_string($destination);
  $priority = $conn->real_escape_string($priority);

  $sql = "INSERT INTO users (boarding, destination, priority, price) VALUES ('$boarding', '$destination', '$priority', '$price')";

  if ($conn->query($sql) === TRUE) {
    echo 'Reservation successful!';
  } else {
    echo 'Error: ' . $sql . '<br>' . $conn->error;
  }

  $conn->close();
}

function calculatePrice($from, $to, $class) {
  if($class==='business')
  {
    $baseprice=750;
  }
  elseif($class==='firstclass')
  {
    $baseprice=500;
  }
  elseif($class==='economy')
  {
    $baseprice=350;
  }
  else{
    echo 'Error:Wrong class entered';
  }
  if ((($from==='Hyderabad')&&($to==='Delhi'))||(($from==='Delhi')&&($to==='Hyderabad'))) {
    $base=7000;
  }
  elseif ((($from==='Hyderabad')&&($to==='Vizag'))||(($from==='Vizag')&&($to==='Hyderabad'))) {
    $base=4500;
  }
  elseif ((($from==='Hyderabad')&&($to==='Bangalore'))||(($from==='Bangalore')&&($to==='Hyderabad'))) {
    $base=5500;
  }
  elseif ((($from==='Vizag')&&($to==='Delhi'))||(($from==='Delhi')&&($to==='Vizag'))) {
    $base=7500;
  }
  elseif ((($from==='Bangalore')&&($to==='Delhi'))||(($from==='Delhi')&&($to==='Bangalore'))) {
    $base=5000;
  }
  elseif ((($from==='Vizag')&&($to==='Bangalore'))||(($from==='Bangalore')&&($to==='Vizag'))) {
    $base=4000;
  }
  else {
    echo "Error:Wrong Destination or Boarding point";
  }
  $total=$base+$baseprice;
  return $total;

}
?>
