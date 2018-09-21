	//Generate a random number
	function rand(upper){
	
		var num;
		num =  Math.floor(Math.random() * upper);
		
		return num;
	}

	//returns a list takes the upper limit	
	function makeList(upperLimit, numItems)
	{
		var locList = [];

		for(var i = 0; i < 10; i++)
		{
			locList.push(rand(10));
		}

		return locList;
	}
	
	function showList(list)
	{
		for(var i = 0; i < list.length; i++)
		console.log(list[i]);
	}

	function convertString(str)
	{
		var locString = str.replace(/\s/g, "");
		locString = locString.toLowerCase();
		var stringArr = locString.split("");

		var asciiArr = [];

		for(var i = 0; i < stringArr.length; i++)
		{
			asciiArr[i] = stringArr[i].charCodeAt();
		}

		return asciiArr;

	}


	function compare(list)
	{
		var locList = [];
		var x = 1;
		var j = 0;

		while(x < list.length)
		{
			locList[j] = 0;
		
			for(var i = 0; i < list.length; i++)
			{
				if( list[i]-list[i+x] == 0 )
				{
					locList[j] += 1;
				}
			}
			x++;	
			j++;
		}

		return locList;

	}
		

	var list = makeList(10, 10);
	console.log(list.join("-"));
	var statList = compare(list); 
	console.log(statList.join("-"));
//	console.log("a".charCodeAt(0));
	
	var str = "HHHHHHH";

	console.log(convertString(str));
