function BTConnect(Theta1,Theta2)

fprintf('\nstarting up connection to bluetooth\n');
bt = Bluetooth('PANTECH', 1);
pause(1);
fopen(bt);
fprintf('\nConnection initiated\n');
%if ff==-1
    
 %       fprintf('\nerror opening bluetooth port');
  %      return
%end;



i=1;count=1;
while i==1
    while 1
    fprintf('\nwaiting for keypress\n');pause(5);
    
    if bt.BytesAvailable>0 %600 indicates keypress
        ss=str2double(fscanf(bt));
        break;
    else %indicates no keypress
        pause(1);
    end;
    end;

    fprintf('\nreading image\n');pause(2);
    pred=imglook(Theta1,Theta2,count);
count=count+1;
%fwrite(bt,pred);
pause(1);display(pred);
x=input('\n enter 1 to continue and 2 to stop communication\n');
if x==2
    
    i=i+1;
        
elseif x==1
        
i=1;
end;

end;
fwrite(bt,9);
fclose(bt);close all;

end