//let and const

// let name = "John Doe"; // depends on scope
// var age = 30; // does not depends on scope
// {
//   console.log(name);
//   console.log(age);
// }

// for (let i = 0; i < 5; i++) {
//   console.log(i);
// }
// let i = 0;
// while (i < 5) {
//   console.log(i);
//   i++;
// }

const data = {
  name: "John Doe",
  age: 30,
};

console.log(data.name, data["age"]);

function Person(first, last, age, job) {
  this.first = first;
  this.last = last;
  this.age = age;
  this.job = job;
  this.name = first + " " + last;
}

const john = new Person("John", "Doe", 30, "Software Engineer");
john.profession = "plumber";

console.log(john.first);
console.log(john.last);
console.log(john.age);
console.log(john.job);
console.log(john.name);
console.log(john.profession);
