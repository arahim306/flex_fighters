function [outfname, rows, cols] = lutgen(infile, outfname, numrows, numcols)

img = imread(infile);

imgresized = imresize(img, [numrows numcols]);

[rows, cols, rgb] = size(imgresized);

imgscaled = imgresized/16 - 1;
imshow(imgscaled*16);

fid = fopen(outfname,'w');

% fprintf(fid,'-- %3ux%3u 12bit image color values\n\n',rows,cols);
% fprintf(fid,'WIDTH = 12;\n');
% fprintf(fid,'DEPTH = %4u;\n\n',rows*cols);
% fprintf(fid,'ADDRESS_RADIX = UNS;\n');
% fprintf(fid,'DATA_RADIX = UNS;\n\n');
% fprintf(fid,'CONTENT BEGIN\n');

fprintf(fid,'{');

count = 0;
for r = 1:rows
    for c = 1:cols
        red = uint16(imgscaled(r,c,1));
        green = uint16(imgscaled(r,c,2));
        blue = uint16(imgscaled(r,c,3));
        color = red*(256) + green*16 + blue;
        fprintf(fid,'%4u,',color);
        if mod(count, 20) == 0
            fprintf(fid,'\n');
        end
        count = count + 1;
    end
end
fprintf(fid,'}');
fclose(fid);