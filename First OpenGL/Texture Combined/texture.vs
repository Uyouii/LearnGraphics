#version 330 core
layout (location = 0) in vec3 aPos;   // Î»ÖÃ±äÁ¿µÄÊôÐÔÎ»ÖÃÖµÎª 0 
layout (location = 1) in vec3 aColor; // ÑÕÉ«±äÁ¿µÄÊôÐÔÎ»ÖÃÖµÎª 1

out vec3 ourColor; // ÏòÆ¬¶Î×ÅÉ«Æ÷Êä³öÒ»¸öÑÕÉ«

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor; // ½«ourColorÉèÖÃÎªÎÒÃÇ´Ó¶¥µãÊý¾ÝÄÇÀïµÃµ½µÄÊäÈëÑÕÉ«
}