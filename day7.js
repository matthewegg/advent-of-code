const fs = require("fs");
const contents = fs.readFileSync("input", "utf-8").split("\r\n").map(x => x.split(" "));

var high_card = [];
var one_pair = [];
var two_pair = [];
var three_of_a_kind = [];
var full_house = [];
var four_of_a_kind = [];
var five_of_a_kind = [];

function letter_to_value(letter) {
    switch (letter) {
        case "J":
            return 0;
        case "T":
            return 10;
        case "J":
            return 11;
        case "Q":
            return 12;
        case "K":
            return 13;
        case "A":
            return 14;
        default:
            return parseInt(letter);
    }
}

function sort_cards(a, b) {
    for (let i = 0; i <= 5; i++) {
        var char_a = letter_to_value(a[0][i]);
        var char_b = letter_to_value(b[0][i]);
        if (char_a !== char_b) {
            if (char_a > char_b) {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
    return 0;
}

for (const line of contents) {
    chars = {};
    var joker_count = 0;

    for (const char of line[0]) {
        if (char === "J") {
            joker_count++;
        }
        else {
            chars[char] == undefined ? chars[char] = 1 : chars[char]++;
        }
    }

    const keys = Object.keys(chars);
    const values = Object.values(chars);
    var hand_type = Math.max(...values);

    if (joker_count > 0) {
        hand_type = hand_type + joker_count > 5 ? 5 : hand_type + joker_count;
    }

    if (keys.length === 1 || joker_count === 5) {
        five_of_a_kind.push(line);
    }
    else if (keys.length === 2) {
        if (hand_type === 4) {
            four_of_a_kind.push(line);
        }
        else {
            full_house.push(line);
        }
    }
    else if (keys.length === 3) {
        if (hand_type == 3) {
            three_of_a_kind.push(line);
        }
        else {
            two_pair.push(line);
        }
    }
    else if (keys.length === 4) {
        one_pair.push(line);
    }
    else {
        high_card.push(line);
    }
}

five_of_a_kind.sort(sort_cards);
four_of_a_kind.sort(sort_cards);
full_house.sort(sort_cards);
three_of_a_kind.sort(sort_cards);
two_pair.sort(sort_cards);
one_pair.sort(sort_cards);
high_card.sort(sort_cards);

const sorted_cards = [...high_card, ...one_pair, ...two_pair, ...three_of_a_kind, ...full_house, ...four_of_a_kind, ...five_of_a_kind];
var part2 = 0;

for (let i = 0; i < sorted_cards.length; i++) {
    part2 += (i + 1) * parseInt(sorted_cards[i][1]);
    console.log(sorted_cards[i]);
}

console.log(part1);
