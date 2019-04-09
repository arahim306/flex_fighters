library ieee;
use ieee.std_logic_1164.all;

entity VGA_sync_gen_tb is
end VGA_sync_gen_tb;

architecture TB of VGA_sync_gen_tb is

	signal clk, rst                           : std_logic := '0';
	signal Hcount, Vcount                     : std_logic_vector(9 downto 0);
	signal Horiz_sync, Vert_sync, Video_On    : std_logic;

begin

	U_VGA_SYNC : entity work.VGA_sync_gen
		port map(
			clk => clk,
			rst => rst,
			Hcount => Hcount,
			Vcount => Vcount,
			Horiz_sync => Horiz_sync,
			Vert_sync => Vert_sync,
			Video_On => Video_On
		);

	clk <= not clk after 20 ns;
	
	process
	begin

		rst <= '1';

		for i in 0 to 20 loop
			wait until (clk'event and clk = '1');
		end loop;

		rst <= '0';
		for i in 0 to 430000 loop
			wait until (clk'event and clk = '1');
		end loop;

	end process;
end TB;