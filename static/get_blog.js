	list_all=new Array;
	from_="";
	function list(x,page){
		var i;
		var para=document.getElementsByClassName("blog");
		for(i=0;i<6;i++)
			{
				para[i].innerHTML="";
				para[i].style.display="none";
			}
			pages=0;
			//alert(page)
		var request=getHttpObject();
		 if(request)
		 	{
			switch(x)
			{
				case 2 :url="./blog/essay/";
						list_url="./list/list_essay.html";
						from_="handle";
						this_page=1;
						break;
				case "#handle" :url="./blog/essay/";
						list_url="./list/list_essay.html";
						from_="handle";
						break;
				case 1 :url="./blog/introPage/";
						list_url="./list/list_tech.html";
						this_page=1;
						from_="home";
						break;
				case "#home" :url="./blog/tech/";
						list_url="./list/list_tech.html";
						from_="home";
						break;
				case "#all":
				case 3:url="./blog/";
						list_url="./list/list_all.html";
						from_="all";
						break;
			}
			request.open("GET",list_url,true);
			request.onreadystatechange=function(){
				if(request.readyState==4)
						{
						list_all=request.responseText.split("\n");
						var len=leng=list_all.length;
						for(leng;leng>0;)
							{
								leng=leng-6;
								pages++;
							}

			input=document.getElementsByTagName("input")[1];
			// if(pages<=1){input.disabled="true"}
			// 	else(input.disabled="false")

			switch(page)
			{
				case 5:page=parseInt(input.value)-1;
				case 1:		
						if(page<=1)
							document.getElementById("prev").style.visibility="hidden";
						else {
							document.getElementById("prev").style.visibility="visible";
						};
						if(page>=pages)
							{document.getElementById("next").style.visibility="hidden"}
						else {
							document.getElementById("next").style.visibility="visible";
						};

						break;
				case 6:page=parseInt(input.value)+1;
				case 1:	if(page>=pages)
							{document.getElementById("next").style.visibility="hidden"}
						else {
							document.getElementById("next").style.visibility="visible";
						};
						if(page<=1)
							document.getElementById("prev").style.visibility="hidden";
						else {
							document.getElementById("prev").style.visibility="visible";
						};
						break;
				case 7:page=parseInt(input.value);
				case 1:	if(page>=pages)
							{document.getElementById("next").style.visibility="hidden"}
						else {
							document.getElementById("next").style.visibility="visible";
						};
						if(page<=1)
							document.getElementById("prev").style.visibility="hidden";
						else {
							document.getElementById("prev").style.visibility="visible";
						};
						break;
			}

						all_page=document.getElementById("all_page");
						all_page.innerHTML=pages;
						input.value=page;
						input.max=pages;
						document.getElementById("page").style.display="block";
						var all=6*page;
						// alert(all);
							for(n=(page-1)*6;n<all;n++)
								{
									//alert(list_all[n]);
									getArtical(list_all[n],url,n-6*(page-1));
									if(page*6>len)
										all=len;

									//alert(all);	
								}
						}
				};
			request.send(null);
			}
			else
			{
				alert("Error");
			}
		}


	function getArtical(src,url,n)
	{
		var request=getHttpObject();
		src=url+src;
		//alert(src);
		var para=document.getElementsByClassName("blog")[n];
		if(request)
		{
			request.open("GET",src,true);
			request.onreadystatechange=function(){
				if(request.readyState==4)
						{
							
							var page=request.responseText;
							para.innerHTML=MakeText(request.responseText);
							para.style.display="block";
							if(from_ == "home" && n == 0)
							{
								paraA = para.getElementsByTagName('a');
								paraALen = paraA.length;
								Show_this(paraA[paraALen - 2]);
							}
				}};
			request.send(null);
		}else
		{
			alert("error");
		}
	}
	function MakeText(texts)
	{
		text=texts.split("<article>");//top
		temp=text[1].split("</article>");
		tit=text[0].split("<tit>");
		text[1]=temp[0];//body
		text[2]=temp[1];//tag
		para=text[1].split("<p>");
		temp=para[1].split("</p>")[0];
		first_para=temp;
		temp=text[2].split("<more>");
		text[3]=temp[1];
		text[3]=text[3].split("</more>")[0];
		text[2]=temp[0];
		tit[1]="<a onclick=\"Show_this(this)\" id=\""+text[3]+"\">"+"<tit>"+tit[1]+"</a>";
		tit[0]="<img src=\"./images/date.png\">"+tit[0];
		text[0]=tit[0]+tit[1];
		if(from_=="all")
		return text[0]+"<hr>"+text[2]+"<a class=\"more\" onclick=\"Show_this(this)\""+"id=\""+text[3]+"\">more>><a/>";
		else
		return text[0]+"<hr>"+"<p>"+first_para+"</p>"+"<hr>"+text[2]+"<a class=\"more\" onclick=\"Show_this(this)\""+"id=\""+text[3]+"\">more>><a/>";
	}
	function Show_this(x)
	{
		var request=getHttpObject();
		src=x.id;


		// comment="<div class=\"ds-thread\" data-thread-key=\""+src+"\"data-title=\"请替换成文章的标题\" data-url=\"http://caibingcheng.github.io/\"></div>"


		//alert(src);
		if(request)
		{
			request.open("GET",src,true);
			request.onreadystatechange=function(){
				if(request.readyState==4)
						{
							var para=x.parentNode;
							text=request.responseText.split("<more>");
							para.innerHTML="<img src=\"./images/date.png\">"+text[0]+"<a class=\"more\" onclick=\"Pack_this(this)\""+"id=\""+src+"\">pack^</a>"+"<hr id=\"bottom_hr\"/>";
						}

			};
			request.send(null);
		}else
		{
			alert("error");
		}
	}
		function Pack_this(x)
	{
		var request=getHttpObject();
		src=x.id;
		//alert(src);
		if(request)
		{
			request.open("GET",src,true);
			request.onreadystatechange=function(){
				if(request.readyState==4)
						{
							var para=x.parentNode;
							text=MakeText(request.responseText);
							para.innerHTML=text;
						}

			};
			request.send(null);
		}else
		{
			alert("error");
		}
	}