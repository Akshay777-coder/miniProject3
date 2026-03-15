<h1>User File System (CLI Project in C)</h1>

<p>
A simple <b>Command Line User File System</b> built using the C programming language.
This project demonstrates basic concepts of:
</p>

<ul>
<li>User Authentication (Signup & Login)</li>
<li>File Handling in C</li>
<li>Directory Management</li>
<li>Menu Driven CLI Programs</li>
<li>Basic File System Simulation</li>
</ul>

<hr>

<h2>Project Features</h2>

<ul>
<li><b>User Signup</b> – Create a new user account.</li>
<li><b>User Login</b> – Authenticate using username and password.</li>
<li><b>Automatic User Directory Creation</b> – Each user gets their own folder.</li>
<li><b>Create / Write Files</b> – Create and store text files.</li>
<li><b>Read Files</b> – Display file contents.</li>
<li><b>Append Files</b> – Add new content to existing files.</li>
<li><b>List Files</b> – View all files in the user directory.</li>
<li><b>Logout System</b> – Return to authentication menu.</li>
</ul>

<hr>

<h2>Project Structure</h2>

<pre>
project-folder/
│
├── main.c
├── users.txt
│
├── username1/
│   ├── file1.txt
│   └── file2.txt
│
└── username2/
    └── notes.txt
</pre>

<p>
Each user has their own directory where their files are stored.
</p>

<hr>

<h2>Technologies Used</h2>

<ul>
<li>C Programming Language</li>
<li>Standard C Libraries</li>
<li>File Handling</li>
<li>System Commands</li>
</ul>

<hr>

<h2>Libraries Used</h2>

<ul>
<li><code>stdio.h</code> – Input / Output operations</li>
<li><code>stdlib.h</code> – Memory and system functions</li>
<li><code>string.h</code> – String handling</li>
<li><code>sys/stat.h</code> – Directory creation</li>
<li><code>direct.h</code> – Windows directory support</li>
</ul>

<hr>

<h2>How It Works</h2>

<ol>
<li>The program starts with an authentication menu.</li>
<li>User can either <b>Signup</b> or <b>Login</b>.</li>
<li>During signup:
    <ul>
        <li>User credentials are stored in <code>users.txt</code>.</li>
        <li>A personal directory is created for that user.</li>
    </ul>
</li>

<li>After successful login, the user panel appears.</li>

<li>The user can:
    <ul>
        <li>Create files</li>
        <li>Read files</li>
        <li>Append content</li>
        <li>List all files</li>
    </ul>
</li>

<li>Files are stored inside the user's directory.</li>
</ol>

<hr>

<h2>Compilation</h2>

<h3>Linux / macOS</h3>

<pre>
gcc main.c -o filesystem
./filesystem
</pre>

<h3>Windows (MinGW / GCC)</h3>

<pre>
gcc main.c -o filesystem.exe
filesystem.exe
</pre>

<hr>

<h2>Example Workflow</h2>

<pre>
--- WELCOME TO USER FILE SYSTEM ---

1. Login
2. Signup
3. Exit

Enter choice: 2
Username: akshay
Password: 1234

Account created! Directory 'akshay/' is ready.

--- USER PANEL: akshay ---

1. Create/Write File
2. Read File
3. Append File
4. List Files
5. Logout
</pre>

<hr>

<h2>Learning Concepts Demonstrated</h2>

<ul>
<li>Structs in C</li>
<li>File I/O operations</li>
<li>Directory handling</li>
<li>Command line interface design</li>
<li>Menu driven programs</li>
<li>Basic operating system concepts</li>
</ul>

<hr>

<h2>Future Improvements</h2>

<ul>
<li>Password encryption</li>
<li>Delete file feature</li>
<li>Rename files</li>
<li>User profile management</li>
<li>Better input validation</li>
<li>Cross-platform file listing without system()</li>
</ul>

<hr>

<h2>Author</h2>

<p>
<b>Akshay</b><br>
C Programming Practice Project
</p>
