library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.math_real.all;

entity clk_div is
    port (
        clk       : in  std_logic;
        pixel_clk : out std_logic;
        rst       : in  std_logic);
end clk_div;

architecture DIVIDER of clk_div is

	signal temp : std_logic;
	signal count : integer range 0 to 1 := 0;

begin
	
	process(clk, rst)
	
	begin

	if(rst = '1') then
		temp <= '0';
		count <= 0;
	elsif rising_edge(clk) then
		if (count = 1) then
			temp <= '1';
			count <= 0;
		else
			temp <= '0';
			count <= count + 1;

		end if;
	end if;

	end process;

	pixel_clk <= temp;

end DIVIDER;