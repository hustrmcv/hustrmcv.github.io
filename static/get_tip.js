	function Show_tip()
	{
		tip=document.createElement("div");
		tip.setAttribute("class","tip");
		document.getElementsByClassName("tips")[0].insertBefore(tip,document.getElementById("son"));
		var tips=document.getElementsByClassName("tip")[0];
		tips.style.display="block";
		tips.innerHTML="<button onclick=\"Display_tip()\">X</button>";
	}
	function Display_tip()
	{
		var tips=document.getElementsByClassName("tip")[0];
		tips.style.display="none";
		tips.innerHTML="";
		var tips=document.getElementsByClassName("tips")[0];
		tips.innerHTML="<button href=\"#\" id=\"show\" onclick=\"Show_tip();getContent()\"><img src=\"./images/tips.jpg\" alt=\"介绍\"></button><div id=\"son\"></div>";
	}

	function getContent()
	{
		var request=getHttpObject();
		if(request)
		{
			request.open("GET","./text/left_tip.html",true);
			request.onreadystatechange=function(){
				if(request.readyState==4)
						{
							var para=document.getElementsByClassName("tip")[0];
							para.innerHTML+=request.responseText;
						}

			};
			request.send(null);
		}else
		{
			alert("error");
		}
	}
	function getHttpObject()
	{
		return new XMLHttpRequest();
	}