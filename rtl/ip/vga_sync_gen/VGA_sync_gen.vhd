library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;
use work.vga_lib.all;

entity VGA_sync_gen is
	port (
		clk           : in std_logic;
		rst           : in std_logic;
		Hcount        : out std_logic_vector(9 downto 0);
		Vcount        : out std_logic_vector(9 downto 0);
		Horiz_sync    : out std_logic;
		Vert_sync     : out std_logic;
		Video_On      : out std_logic
	);
end VGA_sync_gen;

architecture VGA_SYNC of VGA_sync_gen is 
	signal Hcount_temp     : unsigned(9 downto 0);
	signal Vcount_temp     : unsigned(9 downto 0);
begin

	process(clk, rst, Hcount_temp, Vcount_temp)
	begin
		if(rst = '1') then
			Hcount_temp <= "0000000000";
			Vcount_temp <= "0000000000";
			Horiz_Sync  <= '1';
			Vert_sync   <= '1';
			Video_On    <= '0';

		elsif(clk'event and clk = '1') then

			--Incrementing Hcount
			if(Hcount_temp = H_MAX) then
				Hcount_temp <= "0000000000";
			else
				Hcount_temp <= Hcount_temp + 1;
			end if;

			--Incrementing Vcount
			if(Vcount_temp = V_MAX and Hcount_temp = H_VERT_INC) then
				Vcount_temp <= "0000000000";
			elsif(Hcount_temp = H_VERT_INC) then
				Vcount_temp <= Vcount_temp + 1;
			end if;

			--Assigning Horiz_sync
			if(Hcount_temp >= HSYNC_BEGIN and Hcount_temp < HSYNC_END) then
				Horiz_sync <= '0';
			else
				Horiz_sync <= '1';
			end if;

			--Assigning Vert_sync
			if(Vcount_temp >= VSYNC_BEGIN and Vcount_temp <= VSYNC_END) then
				Vert_sync <= '0';
			else
				Vert_sync <= '1';
			end if;

			--Assigning Video_On
			if(Hcount_temp < H_DISPLAY_END and Vcount_temp < v_DISPLAY_END) then
				VideO_On <= '1';
			else
				Video_On <= '0';
			end if;

		end if;

		Hcount <= std_logic_vector(Hcount_temp);
		Vcount <= std_logic_vector(Vcount_temp);

	end process;


end VGA_SYNC;