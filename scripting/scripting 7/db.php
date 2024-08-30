<?php
// Establish connection to MySQL database
$servername = "localhost";
$username = "1234";
$password = "1234";
$dbname = "student_management";

$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Add Student
function addStudent($name, $email, $subject, $marks) {
    global $conn;
    $sql = "INSERT INTO students (name, email, subject, marks) VALUES ('$name', '$email', '$subject', $marks)";
    return mysqli_query($conn, $sql);
}

// Get All Students
function getStudents() {
    global $conn;
    $sql = "SELECT * FROM students";
    $result = mysqli_query($conn, $sql);
    $students = mysqli_fetch_all($result, MYSQLI_ASSOC);
    return $students;
}

// Update Student
function updateStudent($student_id, $name, $email, $subject, $marks) {
    global $conn;
    $sql = "UPDATE students SET name='$name', email='$email', subject='$subject', marks=$marks WHERE student_id=$student_id";
    return mysqli_query($conn, $sql);
}

// Delete Student
function deleteStudent($student_id) {
    global $conn;
    $sql = "DELETE FROM students WHERE student_id=$student_id";
    return mysqli_query($conn, $sql);
}
?>
