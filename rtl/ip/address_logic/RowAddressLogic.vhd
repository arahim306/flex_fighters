library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;
use work.vga_lib.all;

entity RowAddressLogic is
	port (
		Vcount        : in std_logic_vector(9 downto 0);
		Hcount        : in std_logic_vector(9 downto 0);
		Video_On      : in std_logic;
		RowAddress    : out std_logic_vector(7 downto 0);
		Row_en        : out std_logic;
		brick_en 	  : out std_logic
	);
end RowAddressLogic;

architecture RowAddress of RowAddressLogic is
	
begin
	
	process(Vcount, Video_On)
		variable temp : unsigned(9 downto 0);
	begin

		-- default values 
		brick_en <= '0';
		--Ensure we are not refreshing
		if(Video_On = '1') then

			if(unsigned(Vcount) >= TOP_BRICK_Y_START and unsigned(Vcount) < TOP_BRICK_Y_END) then
				temp := shift_right(unsigned(Vcount) - TOP_BRICK_Y_START, 2);
				RowAddress <= std_logic_vector(temp(7 downto 0));
				Row_en <= '1';
				brick_en <= '1';
			elsif(unsigned(Vcount) >= BOTTOM_BRICK_Y_START and unsigned(Vcount) < BOTTOM_BRICK_Y_END) then
				temp := shift_right(unsigned(Vcount) - BOTTOM_BRICK_Y_START, 2);
				RowAddress <= std_logic_vector(temp(7 downto 0));
				Row_en <= '1';
				brick_en <= '1';
			elsif(unsigned(Vcount) >= LEFT_BOXER_Y_START and unsigned(Vcount) < LEFT_BOXER_Y_END) then
				temp := unsigned(Vcount) - LEFT_BOXER_Y_START;
				RowAddress <= std_logic_vector(temp(7 downto 0));
				Row_en <= '1';
				brick_en <= '0';
			else
				temp := (others => '0');
				RowAddress <= (others => '0');
				Row_en <= '0';
				brick_en <= '0';
			end if;

		--avoid latches!
		else
			temp := (others => '0');
			RowAddress <= (others => '0');
			Row_en <= '0';
		end if;

	end process;
end RowAddress;