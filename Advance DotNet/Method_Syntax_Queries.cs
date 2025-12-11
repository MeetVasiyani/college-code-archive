var students = new List<Student>
{
 new Student { Rno = 1, Name = "Amit", Branch = "CE", Sem = 3, CPI = 8.5, Age = 20 },
 new Student { Rno = 2, Name = "Priya", Branch = "IT", Sem = 5, CPI = 9 , Age = 21 },
 new Student { Rno = 3, Name = "Rahul", Branch = "CE", Sem = 1, CPI = 7 , Age = 19 },
 new Student { Rno = 4, Name = "Sneha", Branch = "ME", Sem = 7, CPI = 8 , Age = 22 },
 new Student { Rno = 5, Name = "Karan", Branch = "IT", Sem = 3, CPI = 6 , Age = 20 }
};

var courses = new List<Course>
{
 new Course { Rno = 1, CourseName = "DBMS", Credits = 4 },
 new Course { Rno = 1, CourseName = "C#", Credits = 3 },
 new Course { Rno = 2, CourseName = "Java", Credits = 4 },
 new Course { Rno = 3, CourseName = "Python", Credits = 3 },
 new Course { Rno = 5, CourseName = "AI", Credits = 5 }
};

static void print(IEnumerable<Student>? s)
{
    foreach (var student in s)
    {
        Console.WriteLine($"{student.Rno} {student.Name} {student.Branch} {student.Sem} {student.CPI} {student.Age}");
    }
}

// 1. Get all CE branch students.
Console.WriteLine("CE Branch Students:");
var result = students.Where(s => s.Branch == "CE");

print(result);

// 2. Students having CPI > 8.
Console.WriteLine("\nStudents having CPI > 8:");

var result1 = students.Where(s => s.CPI > 8);

print(result1);
// 3. Students older than 20.
Console.WriteLine("\nStudents older than 20:");
var result3 = students.Where(s => s.Age > 20);

print(result3);

// 4. Students in Semester 3.
Console.WriteLine("\nStudents in Semester 3:");
var result4 = students.Where(s => s.Sem == 4);
print(result4);
// 5. CPI between 7 and 9.
Console.WriteLine("\nStudents with CPI between 7 and 9:");

var result5 = students.Where(s => s.CPI > 7 && s.CPI < 9);

print(result5);

// 6. Name starting with 'A'.
Console.WriteLine("\nName starting with 'A'");

var result6 = students.Where(s => s.Name.StartsWith('A'));

print(result6);
// 7. Branch = IT AND Sem = 3.
Console.WriteLine("\nBranch = IT AND Sem = 3.");

var result7 = students.Where(s => s.Branch == "IT" && s.Sem == 3);

print(result7);
// 8. Age < 20 OR CPI > 8.
Console.WriteLine("\nAge < 20 OR CPI > 8");

var result8 = students.Where(s => s.Age < 20 || s.CPI > 8);

print(result8);
// 9. Names containing 'a'.
Console.WriteLine("\nNames containing 'a'");

var result9 = students.Where(s => s.Name.Contains('a'));

print(result9);
// 10. Students NOT in CE.
Console.WriteLine("\nStudents NOT in CE");

var result10 = students.Where(s => s.Branch != "CE");

print(result10);
// 11. Sem in {1,3,5}.
Console.WriteLine("\nSem in {1,3,5}");
var result11 = students.Where(s => s.Sem == 1 || s.Sem == 3 || s.Sem == 5);

print(result11);
// 12. Students whose CPI is a whole number.
Console.WriteLine("\nStudents whose CPI is a whole number.");
var result12 = students.Where(s => s.CPI % 1 == 0);

print(result12);

// 13. Students with even Roll No.
Console.WriteLine("\nStudents with even Roll No.");
var result13 = students.Where(s => s.Rno % 2 == 0);

print(result13);

// 14. Students whose age is between 18 and 21.
Console.WriteLine("\nStudents whose age is between 18 and 21.");
var result14 = students.Where(s => s.Age >= 18 && s.Age <= 21);

print(result14);

// 15. Students having name length > 4.
Console.WriteLine("\nStudents having name length > 4.");
var result15 = students.Where(s => s.Name.Length > 4);

print(result15);

// 16. Select only names.
Console.WriteLine("\n Select only names");
var result16 = students.Select(s => s.Name);
foreach (var name in result16)
{
    Console.WriteLine(name);
}

// 17. Select Name + CPI.
Console.WriteLine("\nSelect Name + CPI.");
var result17 = students.Select(s => new { s.Name, s.CPI });

foreach (var item in result17)
{
    Console.WriteLine($"{item.Name} {item.CPI}");
}

Console.WriteLine("\nSelect Roll No + Branch.");

// 18. Select Roll No + Branch.
var result18 = students.Select(s => new { s.Rno, s.Branch });

foreach (var item in result18)
{
    Console.WriteLine($"{item.Rno} {item.Branch}");
}

// 19. Select anonymous type: Name, Sem, Age.
Console.WriteLine("\nSelect anonymous type: Name, Sem, Age.");
var result19 = students.Select(s => new { s.Name, s.Sem, s.Age });

foreach (var item in result19)
{
    Console.WriteLine($"{item.Name} {item.Sem} {item.Age}");
}

// 20. Create 'FullInfo' string (e.g., "Name (Branch)").
Console.WriteLine("\nCreate 'FullInfo' string (e.g., \"Name (Branch)\").");
var result20 = students.Select(s => $"{s.Name} ({s.Branch})");

foreach (var item in result20)
{
    Console.WriteLine(item);
}

// 21. Project all to CPI only.
Console.WriteLine("\nProject all to CPI only.");
var result21 = students.Select(s => s.CPI);

foreach (var item in result21)
{
    Console.WriteLine(item);
}

// 22. Select Name in lowercase.
Console.WriteLine("\nSelect Name in lowercase.");
var result22 = students.Select(s => s.Name.ToLower());

foreach (var item in result22)
{
    Console.WriteLine(item);
}

// 23. Select Name + Status based on CPI (Good/Average).
Console.WriteLine("\nSelect Name + Status based on CPI (Good/Average).");
var result23 = students.Select(s => new { s.Name, Status = s.CPI > 8 ? "Good" : "Average" });

foreach (var item in result23)
{
    Console.WriteLine($"{item.Name} - {item.Status}");
}

// 24. Extract only distinct branches

Console.WriteLine("\nExtract only distinct branches.");
var result24 = students.Select(s => s.Branch).Distinct();

foreach (var item in result24)
{
    Console.WriteLine(item);
}

// Convert student to “DTO” format (Rno, Name).
Console.WriteLine("\nConvert student to “DTO” format (Rno, Name).");

Console.WriteLine("");
// 26. Sort names alphabetically.
Console.WriteLine("\nSort names alphabetically.");
var result26 = students.OrderBy(s => s.Name);

print(result26);
// 27. Sort by CPI descending.
Console.WriteLine("\nSort by CPI descending.");
var result27 = students.OrderByDescending(s => s.CPI);

print(result27);

// 28. Sort by Sem, then Name.
Console.WriteLine("\nSort by Sem, then Name.");
var result28 = students.OrderBy(s => s.Name).ThenBy(s => s.Name);

print(result28);

// 29. Sort by Age, then CPI desc.
Console.WriteLine("\nSort by Age, then CPI desc.");
var result29 = students.OrderBy(s => s.Age).ThenByDescending(s => s.CPI);

print(result29);

// 30. Sort by Branch.
Console.WriteLine("\nSort by Branch.");
var result30 = students.OrderBy(s => s.Branch);

print(result30);
// 31. Sort by Name length.
Console.WriteLine("\nSort by Name length.");
var result31 = students.OrderBy(s => s.Name);

print(result31);
// 32. Sort by Sem DESC.
Console.WriteLine("\nSort by Sem DESC.");
var result32 = students.OrderBy(s => s.Sem);

print(result32);
// 33. Sort by CPI then Age.
Console.WriteLine("\nSort by CPI then Age.");
var result33 = students.OrderBy(s => s.CPI).ThenBy(s => s.Age);

print(result33);
// 34. Sort by Rno descending.
Console.WriteLine("\nSort by Rno descending.");
var result34 = students.OrderByDescending(s => s.Rno);

print(result34);
// 35. Sort by Branch then Sem.
Console.WriteLine("\nSort by Branch then Sem.");
var result35 = students.OrderBy(s => s.Branch).ThenBy(s => s.Sem);
print(result35);
// 36. Count total students.
Console.WriteLine("\nCount total students");
var result36 = students.Count();
Console.WriteLine(result36);

// 37. Count CE students.
Console.WriteLine("\nCount CE students");
var result37 = students.Count(s => s.Branch == "CE");
Console.WriteLine(result37);

// 38. Max CPI.
Console.WriteLine("\nMax CPI");
var result38 = students.Max(s => s.CPI);
Console.WriteLine(result38);

// 39. Min CPI.
Console.WriteLine("\nMin CPI");
var result39 = students.Min(s => s.CPI);
Console.WriteLine(result39);

// 40. Average CPI.
Console.WriteLine("\nAverage CPI");
var result40 = students.Average(s => s.CPI);
Console.WriteLine(result40);

// 41. Total credits for Rno = 1.
Console.WriteLine("\nTotal credits for Rno = 1");
var result41 = courses.Where(c => c.Rno == 1).Sum(c => c.Credits);
Console.WriteLine(result41);

// 42. Oldest student's age.
Console.WriteLine("\nOldest student's age");
var result42 = students.Max(s => s.Age);
Console.WriteLine(result42);

// 43. Youngest student's age.
Console.WriteLine("\nYoungest student's age");
var result43 = students.Min(s => s.Age);
Console.WriteLine(result43);

// 44. Highest Sem.
Console.WriteLine("\nHighest Sem");
var result44 = students.Max(s => s.Sem);
Console.WriteLine(result44);

// 45. Sum of all credits.
Console.WriteLine("\nSum of all credits");
var result45 = courses.Sum(c => c.Credits);
Console.WriteLine(result45);

// 46. Get first student.
Console.WriteLine("\nGet first student.");
var result46 = students.First();
Console.WriteLine($"{result46.Rno} {result46.Name} {result46.Branch} {result46.Sem} {result46.CPI} {result46.Age}");

// 47. First student with CPI > 9.
Console.WriteLine("\nFirst student with CPI > 9");
var result47 = students.FirstOrDefault(s => s.CPI > 9);
if (result47 != null)
    Console.WriteLine($"{result47.Rno} {result47.Name} {result47.Branch} {result47.Sem} {result47.CPI} {result47.Age}");
else
    Console.WriteLine("No student found with CPI > 9");

// 48. Last student.
Console.WriteLine("\nLast Student");
var result48 = students.Last();
Console.WriteLine(result48);

// 49. Get student at index 2.
Console.WriteLine("\nGet student at index 2");
var result49 = students.Skip(1).Take(1);
Console.WriteLine(result49);

// 50. Single student with Rno = 3.
Console.WriteLine("\nSingle student with Rno = 3.");
var result50 = students.Where(s => s.Rno == 3);
Console.WriteLine(result50);

// 51. Safe single (e.g., Rno = 10).
Console.WriteLine("\nSafe single (e.g., Rno = 10).");
var result51 = students.Where(s => s.Rno == 10);
Console.WriteLine(result51);

// 52. First IT student.
Console.WriteLine("\nFirst IT student");
var result52 = students.First(s => s.Branch == "IT");
Console.WriteLine(result52);

// 53. Last CE student.
Console.WriteLine("\nLast CE student");
var result53 = students.Last(s => s.Branch == "CE");
Console.WriteLine(result53);

// 54. First student older than 18.
Console.WriteLine("\nFirst student older than 18.");
var result54 = students.Where(s => s.Age > 18);
Console.WriteLine(result54);

// 55. Element at index 0.
Console.WriteLine("\nElement at index 0");
var result55 = students.First();
Console.WriteLine(result55);

// 56. Any CE students?
Console.WriteLine("\nAny CE students?");
var result56 = students.Any(s => s.Branch == "CE");
Console.WriteLine(result56);

// 57. All students older than 17?
Console.WriteLine("\nAll students older than 17?");
var result57 = students.All(s => s.Age > 17);
Console.WriteLine(result57);

// 58. Any CPI > 9?
Console.WriteLine("\nAny CPI > 9?");
var result58 = students.Any(s => s.CPI > 9);
Console.WriteLine(result58);

// 59. All semesters are > 0?
Console.WriteLine("\nAll semesters are > 0?");
var result59 = students.All(s => s.Sem > 0);
Console.WriteLine(result59);

// 60. Any student with name length > 6?
Console.WriteLine("\nAny student with name length > 6?");
var result60 = students.Any(s => s.Name.Length > 6);
Console.WriteLine(result60);

// 61. All belong to CE?
Console.WriteLine("\nAll belong to CE?");
var result61 = students.All(s => s.Branch == "CE");
Console.WriteLine(result61);

// 62. Any course with credits > 4?
Console.WriteLine("\nAny course with credits > 4?");
var result62 = courses.Any(c => c.Credits > 4);
Console.WriteLine(result62);

// 63. All credits > 2?
Console.WriteLine("\nAll credits > 2?");
var result63 = courses.All(c => c.Credits > 2);
Console.WriteLine(result63);

// 64. Any course named "Java"?
Console.WriteLine("\nAny course named \"Java\"?");
var result64 = courses.Any(c => c.CourseName == "Java");
Console.WriteLine(result64);

// 65. Any student younger than 18?
Console.WriteLine("\nAny student younger than 18?");
var result65 = students.Any(s => s.Age < 18);
Console.WriteLine(result65);

// 66. Group students by branch.
Console.WriteLine("\nGroup students by branch.");
var result66 = students.GroupBy(s => s.Branch);

foreach (var group in result66)
{
    Console.WriteLine($"Branch: {group.Key}");
    print(group);
}
// 67. Group by Semester.
Console.WriteLine("\nGroup by Semester.");
var result67 = students.GroupBy(s => s.Sem);

foreach (var group in result67)
{
    Console.WriteLine($"Semester : {group.Key}");
}
// 68. Group by Age.
Console.WriteLine("\nGroup by Age.");
var result68 = students.GroupBy(s => s.Age);

foreach (var group in result68)
{
    Console.WriteLine($"Age : {group.Key}");
}

// 69. Group by CPI category (High/Low).
Console.WriteLine("\nGroup by CPI category (High/Low)");
var result69 = students.GroupBy(s => s.CPI > 8 ? "High" : "Low");

foreach (var group in result69)
{
    Console.WriteLine($"CPI Category: {group.Key}");
    print(group);
}

// 70. Group courses by Rno.
Console.WriteLine("\nGroup courses by Rno.");
var result70 = courses.GroupBy(c => c.Rno);

foreach (var group in result70)
{
    Console.WriteLine($"Rno: {group.Key}");
    foreach (var course in group)
    {
        Console.WriteLine($"  {course.CourseName} - {course.Credits}");
    }
}

// 71. Group students by first letter of name.
Console.WriteLine("\nGroup students by first letter of name.");
var result71 = students.GroupBy(s => s.Name[0]);

foreach (var group in result71)
{
    Console.WriteLine($"First Letter: {group.Key}");
    print(group);
}

// 72. Group by Branch then Sem.
Console.WriteLine("\nGroup by Branch then Sem.");
var result72 = students.GroupBy(s => new { s.Branch, s.Sem });

foreach (var group in result72)
{
    Console.WriteLine($"Branch: {group.Key.Branch}, Sem: {group.Key.Sem}");
    print(group);
}

// 73. Group by age range (Teen/Adult).
Console.WriteLine("\nGroup by age range (Teen/Adult).");
var result73 = students.GroupBy(s => s.Age < 20 ? "Teen" : "Adult");

foreach (var group in result73)
{
    Console.WriteLine($"Age Range: {group.Key}");
    print(group);
}

// 74. Group courses by Credits.
Console.WriteLine("\nGroup courses by Credits.");
var result74 = courses.GroupBy(c => c.Credits);

foreach (var group in result74)
{
    Console.WriteLine($"Credits: {group.Key}");
    foreach (var course in group)
    {
        Console.WriteLine($"  {course.CourseName} (Rno: {course.Rno})");
    }
}

// 75. Group students by CPI rounded
Console.WriteLine("\nGroup students by CPI rounded.");
var result75 = students.GroupBy(s => Math.Round(s.CPI));

foreach (var group in result75)
{
    Console.WriteLine($"Rounded CPI: {group.Key}");
    print(group);
}

// 76. Inner Join students + courses.
Console.WriteLine("\nInner Join students + courses.");
var result76 = students.Join(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, course) => new { student.Name, course.CourseName, course.Credits }
);

foreach (var item in result76)
{
    Console.WriteLine($"{item.Name} - {item.CourseName} ({item.Credits} credits)");
}

// 77. Join to get total credits per student.
Console.WriteLine("\nJoin to get total credits per student.");
var result77 = students.GroupJoin(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, studentCourses) => new
    {
        student.Name,
        TotalCredits = studentCourses.Sum(c => c.Credits)
    }
);

foreach (var item in result77)
{
    Console.WriteLine($"{item.Name} - Total Credits: {item.TotalCredits}");
}

// 78. Students with courses (Name, CourseName, Credits).
Console.WriteLine("\nStudents with courses (Name, CourseName, Credits).");
var result78 = students.Join(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, course) => new { student.Name, course.CourseName, course.Credits }
);

foreach (var item in result78)
{
    Console.WriteLine($"{item.Name} - {item.CourseName} ({item.Credits} credits)");
}

// 79. Left join to include students without courses.
Console.WriteLine("\nLeft join to include students without courses.");
var result79 = students.GroupJoin(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, studentCourses) => new
    {
        student.Name,
        student.Branch,
        Courses = studentCourses.Any() ? studentCourses.Select(c => c.CourseName) : new List<string> { "No Courses" }
    }
);

foreach (var item in result79)
{
    Console.WriteLine($"{item.Name} ({item.Branch}) - {string.Join(", ", item.Courses)}");
}

// 80. List of all distinct courses taken.
Console.WriteLine("\nList of all distinct courses taken.");
var result80 = courses.Select(c => c.CourseName).Distinct();

foreach (var item in result80)
{
    Console.WriteLine(item);
}

// 81. Students having more than 1 course.
Console.WriteLine("\nStudents having more than 1 course.");
var result81 = students.GroupJoin(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, studentCourses) => new { student.Name, CourseCount = studentCourses.Count() }
)
.Where(s => s.CourseCount > 1);

foreach (var item in result81)
{
    Console.WriteLine($"{item.Name} - {item.CourseCount} courses");
}

// 82. Join and order by credits.
Console.WriteLine("\nJoin and order by credits.");
var result82 = students.Join(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, course) => new { student.Name, course.CourseName, course.Credits }
)
.OrderBy(item => item.Credits);

foreach (var item in result82)
{
    Console.WriteLine($"{item.Name} - {item.CourseName} ({item.Credits} credits)");
}

// 83. Students of IT with courses.Console.WriteLine("\nStudents of IT with courses.");
var result83 = students.Where(s => s.Branch == "IT")
    .Join(
        courses,
        student => student.Rno,
        course => course.Rno,
        (student, course) => new { student.Name, student.Branch, course.CourseName }
    );

foreach (var item in result83)
{
    Console.WriteLine($"{item.Name} ({item.Branch}) - {item.CourseName}");
}

// 84. Students who have no course.
Console.WriteLine("\nStudents who have no course.");
var result84 = students.GroupJoin(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, studentCourses) => new { Student = student, CourseCount = studentCourses.Count() }
)
.Where(s => s.CourseCount == 0)
.Select(s => s.Student);

print(result84);

// 85. Students + number of courses.
Console.WriteLine("\nStudents + number of courses.");
var result85 = students.GroupJoin(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, studentCourses) => new { student.Name, NumberOfCourses = studentCourses.Count() }
);

foreach (var item in result85)
{
    Console.WriteLine($"{item.Name} - {item.NumberOfCourses} courses");
}


// 86. Distinct branches.
Console.WriteLine("\nDistinct branches.");
var result86 = students.Select(s => s.Branch).Distinct();

foreach (var item in result86)
{
    Console.WriteLine(item);
}

// 87. Students in CE or IT (Union).
Console.WriteLine("\nStudents in CE or IT (Union).");
var ceStudents = students.Where(s => s.Branch == "CE");
var itStudents = students.Where(s => s.Branch == "IT");
var result87 = ceStudents.Union(itStudents);

print(result87);

// 88. Students in CE but not IT (Except).
Console.WriteLine("\nStudents in CE but not IT (Except).");
var result88 = ceStudents.Except(itStudents);

print(result88);

// 89. Common semesters between CE and IT students (Intersect).
Console.WriteLine("\nCommon semesters between CE and IT students (Intersect).");
var ceSemesters = students.Where(s => s.Branch == "CE").Select(s => s.Sem);
var itSemesters = students.Where(s => s.Branch == "IT").Select(s => s.Sem);
var result89 = ceSemesters.Intersect(itSemesters);

foreach (var sem in result89)
{
    Console.WriteLine(sem);
}

// 90. Get all courses that have credits other than 3
Console.WriteLine("\nGet all courses that have credits other than 3.");
var result90 = courses.Where(c => c.Credits != 3);

foreach (var course in result90)
{
    Console.WriteLine($"{course.CourseName} - {course.Credits} credits");
}

// 91. Convert to list.
Console.WriteLine("\nConverted to List:");
var result91 = students.ToList();
print(result91);

// 92. Convert to dictionary (Rno → Name).
Console.WriteLine("\nConverted to Dictionary (Rno -> Name):");
var result92 = students.ToDictionary(s => s.Rno, s => s.Name);
foreach (var entry in result92)
{
    Console.WriteLine($"Rno: {entry.Key}, Name: {entry.Value}");
}

// 93. Convert projected type to array (Names → string[]).
Console.WriteLine("\nConverted projected type to array (Names -> string[]):");
var result93 = students.Select(s => s.Name).ToArray();
foreach (var name in result93)
{
    Console.WriteLine(name);
}

// 94. Create lookup (Rno → Courses).
Console.WriteLine("\nCreate lookup (Rno -> Courses):");
var result94 = courses.ToLookup(c => c.Rno);
foreach (var lookupEntry in result94)
{
    Console.WriteLine($"Rno: {lookupEntry.Key}");
    foreach (var course in lookupEntry)
    {
        Console.WriteLine($"  {course.CourseName} ({course.Credits} credits)");
    }
}

// 95. Convert branch list to HashSet.
Console.WriteLine("\nConvert branch list to HashSet:");
var result95 = students.Select(s => s.Branch).ToHashSet();
foreach (var branch in result95)
{
    Console.WriteLine(branch);
}

// 96. Top 2 highest CPI students.
Console.WriteLine("\nTop 2 highest CPI students.");
var result96 = students.OrderByDescending(s => s.CPI).Take(2);

print(result96);

// 97. Skip first 2, take next 2.
Console.WriteLine("\nSkip first 2, take next 2.");
var result97 = students.Skip(2).Take(2);

print(result97);

// 98. Find student with max CPI (full object).
Console.WriteLine("\nFind student with max CPI (full object).");
var result98 = students.OrderByDescending(s => s.CPI).FirstOrDefault();
if (result98 != null)
    Console.WriteLine($"{result98.Rno} {result98.Name} {result98.Branch} {result98.Sem} {result98.CPI} {result98.Age}");

// 99. Get students with course count + sort by count.
Console.WriteLine("\nGet students with course count + sort by count.");
var result99 = students.GroupJoin(
    courses,
    student => student.Rno,
    course => course.Rno,
    (student, studentCourses) => new { Student = student, CourseCount = studentCourses.Count() }
)
.OrderByDescending(s => s.CourseCount);

foreach (var item in result99)
{
    Console.WriteLine($"{item.Student.Name} - {item.CourseCount} courses");
}

// 100. Show students grouped by Branch and sorted by CPI
Console.WriteLine("\nShow students grouped by Branch and sorted by CPI.");
var result100 = students.GroupBy(s => s.Branch)
                        .Select(group => new
                        {
                            Branch = group.Key,
                            Students = group.OrderByDescending(s => s.CPI).ToList()
                        });

foreach (var group in result100)
{
    Console.WriteLine($"Branch: {group.Branch}");
    print(group.Students);
}

// 101. Show deferred execution: create a query, modify the source, then enumerate to show
// the change.
Console.WriteLine("\nShow deferred execution: create a query, modify the source, then enumerate to show the change.");
var result101 = students.Where(s => s.CPI > 7);
foreach (var group in result101)
{
    Console.WriteLine($"{group.Rno} {group.Name} {group.Branch} {group.Sem} {group.CPI} {group.Age}");
}

students.Add(new Student { Rno = 6, Name = "New Student", Branch = "CE", Sem = 3, CPI = 9.0, Age = 20 });
Console.WriteLine("\nAfter adding a new student (deferred execution):");
foreach (var group in result101)
{
    Console.WriteLine($"{group.Rno} {group.Name} {group.Branch} {group.Sem} {group.CPI} {group.Age}");
}

// 102. Convert deferred to immediate execution (force materialization).
Console.WriteLine("\nConvert deferred to immediate execution (force materialization).");
var result102 = students.Where(s => s.CPI > 8).ToList(); // .ToList() forces immediate execution
students.Add(new Student { Rno = 7, Name = "Another Student", Branch = "IT", Sem = 4, CPI = 9.5, Age = 21 });
Console.WriteLine("After adding another student (immediate execution - no change):");
print(result102);

// 103. Deferred + modifying list: show how changing an element affects query results.
Console.WriteLine("\nDeferred + modifying list: show how changing an element affects query results.");
var result103 = students.Where(s => s.Branch == "IT");
Console.WriteLine("Original IT students (deferred):");
print(result103);

var priya = students.FirstOrDefault(s => s.Name == "Priya");
if (priya != null)
{
    priya.Branch = "CE"; // Modify an existing element
}
Console.WriteLine("After modifying Priya's branch to CE (deferred execution reflects change):");
print(result103);

// 104. Illustrate the multiple-enumeration problem and how to avoid it.
Console.WriteLine("\nIllustrate the multiple-enumeration problem and how to avoid it.");
var query = students.Where(s => s.Age > 20);

Console.WriteLine("First enumeration:");
foreach (var student in query)
{
}
// 105. Deferred with filtering later: create a deferred query then apply further filters before
// enumeration
Console.WriteLine("\nDeferred with filtering later: create a deferred query then apply further filters before enumeration");
var result105 = students.Where(s => s.CPI > 7);
var filteredResult105 = result105.Where(s => s.Age < 22);
foreach (var student in filteredResult105)
{
    Console.WriteLine($"{student.Rno} {student.Name} {student.Branch} {student.Sem} {student.CPI} {student.Age}");
}


// 106. Use let to calculate squared CPI and select Name + squaredCPI.
Console.WriteLine("\nUse let to calculate squared CPI and select Name + squaredCPI.");
var result106 = students.Select(s => new { s.Name, SquaredCPI = s.CPI * s.CPI });

foreach (var item in result106)
{
    Console.WriteLine($"{item.Name} - Squared CPI: {item.SquaredCPI}");
}

// 107. Use let with filtering: compute ageCategory (Teen/Adult) and select names where
// category is "Adult".
var result107 = students.Select(s => new { s.Name, AgeCategory = s.Age < 20 ? "Teen" : "Adult" })
                        .Where(x => x.AgeCategory == "Adult")
                        .Select(x => x.Name);

foreach (var name in result107)
{
    Console.WriteLine(name);
}

// 108. Use let with multiple calculations (e.g., bonusCPI and isHigh) and project Name,
// bonusCPI, isHigh.
Console.WriteLine("\nUse let with multiple calculations (e.g., bonusCPI and isHigh) and project Name, bonusCPI, isHigh.");
var result108 = students.Select(s => new { s.Name, BonusCPI = s.CPI + 0.5 })
                        .Select(x => new { x.Name, x.BonusCPI, IsHigh = x.BonusCPI > 9.0 });

foreach (var item in result108)
{
    Console.WriteLine($"{item.Name} - Bonus CPI: {item.BonusCPI}, Is High: {item.IsHigh}");
}

// 109. Group by branch into groups and select Branch + Count for groups having more than
// one student.
Console.WriteLine("\nGroup by branch into groups and select Branch + Count for groups having more than one student.");
var result109 = students.GroupBy(s => s.Branch)
                        .Where(g => g.Count() > 1)
                        .Select(g => new { Branch = g.Key, Count = g.Count() });
foreach (var item in result109)
{
    Console.WriteLine($"{item.Branch} - Count: {item.Count}");
}
// 110. Group by Sem and select Sem with student names in that Sem.
Console.WriteLine("\nGroup by Sem and select Sem with student names in that Sem.");
var result110 = students.GroupBy(s => s.Sem)
                        .Select(g => new
                        {
                            Sem = g.Key,
                            StudentNames = g.Select(s => s.Name).ToList()
                        });

foreach (var item in result110)
{
    Console.WriteLine($"Semester: {item.Sem}");
    foreach (var name in item.StudentNames)
    {
        Console.WriteLine($"  - {name}");
    }
}

// 111. Nested grouping: group by Branch, then within each branch group by Sem, and select
// Branch, Sem, and student names.
Console.WriteLine("\nNested grouping: group by Branch, then within each branch group by Sem, and select Branch, Sem, and student names.");
var result111 = students.GroupBy(s => s.Branch)
                        .Select(bg => new
                        {
                            Branch = bg.Key,
                            SemGroups = bg.GroupBy(s => s.Sem)
                                          .Select(sg => new
                                          {
                                              Sem = sg.Key,
                                              StudentNames = sg.Select(s => s.Name).ToList()
                                          })
                        });

foreach (var branchGroup in result111)
{
    Console.WriteLine($"Branch: {branchGroup.Branch}");
    foreach (var semGroup in branchGroup.SemGroups)
    {
        Console.WriteLine($"  Semester: {semGroup.Sem}");
        foreach (var name in semGroup.StudentNames)
        {
            Console.WriteLine($"    - {name}");
        }
    }
}

// 112. 3-table join example (Student + Course + Departments) — select Student Name,
// CourseName, DeptHead.
Console.WriteLine("\n3-table join example (Student + Course + Departments) — select Student Name, CourseName, DeptHead.");
var departments = new List<Department>
{
    new Department { Branch = "CE", DeptHead = "Dr. Sharma" },
    new Department { Branch = "IT", DeptHead = "Dr. Verma" },
    new Department { Branch = "ME", DeptHead = "Dr. Gupta" }
};
foreach (var department in departments)
{
    Console.WriteLine($"{department.Branch} - {department.DeptHead}");
}
// 113. For each student compute total credits and include the branch head by joining with
// Departments.
Console.WriteLine("");
var result113 = students.GroupJoin(courses,s => s.Rno,c => c.Rno,(s, c) => new { Student = s, Courses = c })
                        .Join(departments,x => x.Student.Branch,d => d.Branch,(x, d) => new
                            {
                                x.Student.Name,
                                TotalCredits = x.Courses.Sum(c => c.Credits),
                                d.DeptHead
                            });

foreach (var item in result113)
{
    Console.WriteLine($"{item.Name} - Total Credits: {item.TotalCredits}, Dept Head: {item.DeptHead}");
}



// 114. Left join students with Departments, selecting Student Name, Branch, and DeptHead (or
// "No Dept" if missing)
Console.WriteLine("\nLeft join students with Departments, selecting Student Name, Branch, and DeptHead (or \"No Dept\" if missing)");
var result114 = students.GroupJoin(departments,
                                   s => s.Branch,
                                   d => d.Branch,
                                   (s, ds) => new { Student = s, Depts = ds })
                        .SelectMany(x => x.Depts.DefaultIfEmpty(new Department { Branch = x.Student.Branch, DeptHead = "No Dept" }),
                                    (x, dept) => new
                                    {
                                        x.Student.Name,
                                        x.Student.Branch,
                                        dept.DeptHead
                                    });
foreach (var item in result114)
{
    Console.WriteLine($"{item.Name} ({item.Branch}) - Dept Head: {item.DeptHead}");
}