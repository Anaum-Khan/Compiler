var numbers: [Int] = [5, 10, 15, 20, 25];

print(numbers[0]);
print(numbers[2]);
print(numbers[4]);

numbers[1] = 100;
print(numbers[1]);

var counter = 0;
while (counter < 5) {
    print(counter);
    counter = counter + 1;
}

var limit = 3;
for idx in limit {
    print(idx);
}
