// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {

    // STRUCT — groups all fields for one student into a single type
    struct Student {
        uint id;        // auto-assigned unique number
        string name;    // student's full name
        uint age;       // age in years
        string course;  // e.g. "AIML", "OS", "DSA"
        uint marks;     // marks out of 100
    }

    // ARRAY — a dynamic list; grows every time addStudent() is called
    Student[] public students;

    // EVENT — logged on the blockchain whenever a student is added
    event StudentAdded(uint id, string name, uint age, string course, uint marks);

    // WRITE FUNCTION — costs gas; changes blockchain state
    function addStudent(
        string memory _name,
        uint _age,
        string memory _course,
        uint _marks
    ) public {
        uint newId = students.length + 1;
        students.push(Student(newId, _name, _age, _course, _marks));
        emit StudentAdded(newId, _name, _age, _course, _marks);
    }

    // READ FUNCTION — free; does not change state
    function getStudent(uint _index) public view returns (
        uint id, string memory name, uint age,
        string memory course, uint marks
    ) {
        require(_index < students.length, "Index out of bounds");
        Student memory s = students[_index];
        return (s.id, s.name, s.age, s.course, s.marks);
    }

    // READ FUNCTION — returns how many students have been added
    function getStudentCount() public view returns (uint) {
        return students.length;
    }

    // READ FUNCTION — returns the contract's ETH balance
    function showBalance() public view returns (uint) {
        return address(this).balance;
    }
}
