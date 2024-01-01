const fs = require("fs");
const contents = fs.readFileSync("input", "utf-8").split("\r\n").map(x => x.split(" ").filter(c => c.trim().length > 0));

const part2_time = contents[0].slice(1, contents[0].length).join("");
const part2_distance = contents[1].slice(1, contents[1].length).join("");
var part1 = 1;
var part2 = 0;

for (let i = 1; i < contents[0].length; i++) {
    win_count = 0;
    for (let j = 1; j <= contents[0][i]; j++) {
        if (j * (contents[0][i] - j) > contents[1][i]) {
            win_count++;
        }
    }
    part1 *= win_count;
}

for (let k = 1; k <= part2_time; k++) {
    if (k * (part2_time - k) > part2_distance) {
        part2++;
    }
}

console.log(part1);
console.log(part2);