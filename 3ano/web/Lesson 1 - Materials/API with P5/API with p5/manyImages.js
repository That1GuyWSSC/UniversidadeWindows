let api="http://api.giphy.com/v1/gifs/search?";
let apiKey="&api_key=v5ieKu8Ir9AUeVRqQop468KyjUCj9zyD"
let q="&q=fcporto"

let data={}

function setup(){
    noCanvas();
    var url = api + apiKey+q;
    loadJSON(url, gotData);

}


function gotData(giphy){
    for(let i=0; giphy.data.length;i++){
        createImg(giphy.data[i].images.original.url);
    }
}
