let x: Int = 15;
let y: Int = 25;
var z = x + y;

print(x);
print(y);
print(z);

var max = 0;
if (x > y) {
    max = x;
} else {
    max = y;
}
print(max);

var data: [Int] = [100, 200, 300, 400, 500];
print(data[0]);
data[2] = 350;
print(data[2]);

var i = 1;
while (i <= 5) {
    print(i);
    i = i + 1;
}

let choice: Int = 2;
switch choice {
    case 1:
        print(1000);
    case 2:
        print(2000);
    case 3:
        print(3000);
    default:
        print(9999);
}

var loopvar = 4;
for item in loopvar {
    print(item);
}
