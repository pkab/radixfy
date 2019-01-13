const express=require("express");
const bodyp=require("body-parser");
const app=express();
const port=80;

app.use(bodyp.urlencoded({extended:false}));
app.use(bodyp.json());

app.get('/',(request,response)=>{
	response.sendFile('/home/pi/nodeweb/index.html');
});
app.get('/js',(req,res)=>{
	res.sendfile('js/view.js');
});
var strn;
app.post('/live',(req,res)=>{
	console.log(req.body);
	strn=req.body;
	res.send(req.body);
});
app.get('/live',(req,res)=>{
	res.send(strn);
});
app.listen(port,(err)=>{
	if(err){
		console.log(err);
	}
	console.log(`Server listening on port: ${port}`);
});
module.exports={nextval:strn};
