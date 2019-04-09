library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;
use work.vga_lib.all;

entity ColumnAddressLogic is
	port (
		Hcount           : in std_logic_vector(9 downto 0);
		Vcount           : in std_logic_vector(9 downto 0);
		Video_On         : in std_logic;
		ColumnAddress    : out std_logic_vector(6 downto 0);
		Column_en        : out std_logic;
		Player_num		 : out std_logic
	);
end ColumnAddressLogic;

architecture ColumnAddress of ColumnAddressLogic is
begin
	
	process(Hcount, Vcount, Video_On)
		variable temp : unsigned(9 downto 0);
	begin
		Player_num <= '0';
		--Ensure we are not refreshing
		if(Video_On = '1') then
			
			if(unsigned(Vcount) >= TOP_BRICK_Y_START and unsigned(Vcount) < TOP_BRICK_Y_END) then
				temp := shift_left((unsigned(Vcount) - TOP_BRICK_Y_START), 5) + (unsigned(HCOUNT) mod BRICK_WIDTH);
				ColumnAddress <= std_logic_vector(temp(6 downto 0));
				Column_en <= '1';
			elsif(unsigned(Vcount) >= BOTTOM_BRICK_Y_START and unsigned(Vcount) < BOTTOM_BRICK_Y_END) then
				temp := shift_left((unsigned(Vcount) - BOTTOM_BRICK_Y_START), 5) + (unsigned(HCOUNT) mod BRICK_WIDTH);
				ColumnAddress <= std_logic_vector(temp(6 downto 0));
				Column_en <= '1';
			elsif(unsigned(Hcount) >= LEFT_BOXER_X_START and unsigned(Hcount) < LEFT_BOXER_X_END) then
				temp := unsigned(Hcount) - LEFT_BOXER_X_START;
				ColumnAddress <= std_logic_vector(temp(6 downto 0));
				Column_en <= '1';
				Player_num	<= '0';
			elsif(unsigned(Hcount) >= RIGHT_BOXER_X_START and unsigned(Hcount) < RIGHT_BOXER_X_END) then
				temp := 32767 - (unsigned(Hcount) - RIGHT_BOXER_X_START);
				ColumnAddress <= std_logic_vector(temp(6 downto 0));
				Column_en <= '1';
				Player_num <= '1';
			else
				temp := (others => '0');
				ColumnAddress <= (others => '0');
				Column_en <= '0';
			end if;

		--avoid latches!
		else
			temp := (others => '0');
			ColumnAddress <= (others => '0');
			Column_en <= '0';
		end if;

	end process;
end ColumnAddress;