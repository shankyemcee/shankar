function [pred] = imglook(Theta1,Theta2,count) 

x=dir('C:/out/*.bmp');
 a=x(count).name;
 cd C:/out;
Img=imread(a);
 Img=Img(:,:,1);

 
 
 %Img=Img(:);
 %Img=Img';
 %Img=double(Img);
 cd C:\Users\shank\Documents\my_experiment\neural_matlab;
 
 pred=fingernumber(Img);
 
 
 %pred = predict(Theta1, Theta2, Img);

 
 
end