
function list() {
	let obj = {now: null, next: null}
	let link = obj;

	return function(value) {
		if (obj.now == null) {
			obj.now = value;
		} else if (arguments.length) {	
			link.next = {now: value, next: null};
			link = link.next;
		}
		
		return obj;
	}
}

let li3 = list();
li3(1);
li3(2);
li3(3);

console.log(li3());

// expected output {now: 1, next: {now: 2, next: {now: 3, next: null}}}
