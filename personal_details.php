<?php
// Database configuration (change these values accordingly)
$servername = "sql202.byecluster.com";
$username = "if0_34593766";
$password = "x0dPlnpAvs8";
$dbname = "if0_34593766_pdetails";

// Create a database connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check if the connection is successful
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect form data
    $name = $_POST["name"];
    $number = $_POST["number"];
    $aadhar = $_POST["aadhar"];
    $email = $_POST["email"];
    $residence = $_POST["residence"];
    $password = $_POST["password"];

    // Store the form data in the database
    $sql = "INSERT INTO your_table_name (name, number, aadhar, email, residence, password)
            VALUES ('$name', '$number', '$aadhar', '$email', '$residence', '$password')";

    if ($conn->query($sql) === TRUE) {
        // Redirect to the next page on successful submission
        header("Location: next_page.php");
        exit(); // Make sure to include this line to stop the current script execution
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

// Close the database connection
$conn->close();
?>
