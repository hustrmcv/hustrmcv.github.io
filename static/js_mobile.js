flag_1=0;
flag_2=0;
function phone() {
            var sUserAgent = navigator.userAgent.toLowerCase();
            var bIsIpad = sUserAgent.match(/ipad/i) == "ipad";
            var bIsIphoneOs = sUserAgent.match(/iphone os/i) == "iphone os";
            var bIsMidp = sUserAgent.match(/midp/i) == "midp";
            var bIsUc7 = sUserAgent.match(/rv:1.2.3.4/i) == "rv:1.2.3.4";
            var bIsUc = sUserAgent.match(/ucweb/i) == "ucweb";
            var bIsAndroid = sUserAgent.match(/android/i) == "android";
            var bIsCE = sUserAgent.match(/windows ce/i) == "windows ce";
            var bIsWM = sUserAgent.match(/windows mobile/i) == "windows mobile";
            if (bIsIpad || bIsIphoneOs || bIsMidp || bIsUc7 || bIsUc || bIsAndroid || bIsCE || bIsWM) 
            {
            scroll_top=document.body.scrollTop;
            if(scroll_top>113 && flag_1==0)
            	{
            		document.getElementsByTagName('link')[3].href="./static/new_style_mobile.css";
            		flag_1=1;
            	}
            if(scroll_top>290 && flag_2==0)
            	{
            	document.getElementById("name").innerHTML="狼牙@CV";
            	flag_2=1;


                  
            	}
            if(scroll_top<=289 && flag_2==1)
            	{
            	document.getElementById("name").innerHTML="狼牙@CV<p>HUST RoboMaster</p>";
            	flag_2=0;
            	}
       		if(scroll_top<=90 && flag_1==1)
       			{
            		document.getElementsByTagName('link')[3].href="";
            		flag_1=0;
            	}
            }
        }

window.onload=function(){list(1,1);setInterval("phone()",1);}