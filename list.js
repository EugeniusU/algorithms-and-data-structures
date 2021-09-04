class List {
	constructor(now, prev) {
		if (!now && now != 0) {
			this.now = null;
		} else {
			this.now = now;
		}
		if (!prev && now != 0) {
			this.prev = null;
		} else {
			this.prev = prev;
		}
	}
	
	apply(obj) {
		let so = new List(this.now, this.prev);
		
		this.now = obj;
		this.prev = so;
		
	}
}

let li = new List(0);

li.apply(1);
li.apply(2);
li.apply(3);

li.apply(30);


console.log(li);
