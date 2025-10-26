let grade: Int = 85;

if (grade >= 90) {
    print(4);
} else {
    if (grade >= 80) {
        print(3);
    } else {
        if (grade >= 70) {
            print(2);
        } else {
            print(1);
        }
    }
}

let day: Int = 3;
switch day {
    case 1:
        print(100);
    case 2:
        print(200);
    case 3:
        print(300);
    case 4:
        print(400);
    default:
        print(999);
}

var n = 5;
var factorial = 1;
while (n > 0) {
    factorial = factorial * n;
    n = n - 1;
}
print(factorial);
