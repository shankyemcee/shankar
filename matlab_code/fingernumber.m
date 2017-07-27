
function i=fingernumber(I)

%%for picture keep fingers as close to the top of image as possible and for
%%5 fingers keep the thumb as close to left as possible
%%try to make middle finger touch top and thumb touch left

BW=I>70;

x=40:240;a=.01;k=25;h=130;
y=a*(x-h).^2+k;

K=k+80;
Y=a*(x-h).^2+K;


BW(1:ceil(y(1)),1:x(1))=zeros();


j=1;
for i=x(1):x(end)
    
    BW(1:ceil(y(j)),i)=zeros();
    j=j+1;
end;
    

j=1;
for i=x(1)+20:x(end)
    
    BW(ceil(Y(j)):end,i)=zeros();
    j=j+1;
end;
   
    


 BW(:,1:20)=zeros();
 BW(270:end,:)=zeros();
 
imshow(BW);
%% BW(240:end,1:90)=ones();
 %%BW(200:end,170:end)=ones();
 %%BW(1:end,210:end)=ones();
 %%BW(250:end,85:175)=zeros();
 
 
 
 [B,L] = bwboundaries(BW);
i=0;
for j=1:length(B)
    a=B{j};
    if (size(a,1)>30)
          i=i+1;
    end;
end;

i=i-1;
   


%%Here you can see the image with the different regions coloured

    [B,L] = bwboundaries(BW,'noholes');
imshow(label2rgb(L, @jet, [.5 .5 .5]))
hold on
for k = 1:length(B)
   boundary = B{k};
   plot(boundary(:,2), boundary(:,1), 'w', 'LineWidth', 2)
end


figHandle = figure;
figure(figHandle);


end