<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Management</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Student Management System</h1>
        <form action="add_student.php" method="post">
            <input type="text" name="name" placeholder="Name" required>
            <input type="email" name="email" placeholder="Email" required>
            <input type="text" name="subject" placeholder="Subject" required>
            <input type="number" name="marks" placeholder="Marks" required>
            <button type="submit">Add Student</button>
        </form>

        <h2>All Students</h2>
        <table>
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Email</th>
                <th>Subject</th>
                <th>Marks</th>
                <th>Action</th>
            </tr>
            <?php
            include 'db.php';
            $students = getStudents();
            foreach ($students as $student) {
                echo "<tr>";
                echo "<td>" . $student['student_id'] . "</td>";
                echo "<td>" . $student['name'] . "</td>";
                echo "<td>" . $student['email'] . "</td>";
                echo "<td>" . $student['subject'] . "</td>";
                echo "<td>" . $student['marks'] . "</td>";
                echo "<td><a href='edit_student.php?id=" . $student['student_id'] . "'>Edit</a> | <a href='delete_student.php?id=" . $student['student_id'] . "'>Delete</a></td>";
                echo "</tr>";
            }
            ?>
        </table>
    </div>
</body>
</html>
