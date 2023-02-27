let url = 'http://api.giphy.com/v1/gifs/search?api_key=v5ieKu8Ir9AUeVRqQop468KyjUCj9zyD&q=fcporto';

function setup() {
	noCanvas();
	loadJSON(url, gotData);
}

function gotData(giphy) {
	// console.log(giphy.data[0].images.original.url)
	createImg(giphy.data[0].images.original.url);
}
