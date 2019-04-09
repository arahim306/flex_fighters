library ieee;
use ieee.std_logic_1164.all;

entity top_level is
	port (
		nrst            : in std_logic;
		clk             : in std_logic;
		l_boxer_state	: in std_logic_vector(1 downto 0);
		r_boxer_state   : in std_logic_vector(1 downto 0);
		game_state 		: in std_logic_vector(1 downto 0);
		Horiz_sync      : out std_logic;
		Vert_sync       : out std_logic;
		Red             : out std_logic_vector(3 downto 0);
		Green           : out std_logic_vector(3 downto 0);
		Blue            : out std_logic_vector(3 downto 0);
		ce_n			: out std_logic;
		we_n			: out std_logic;
		oe_n			: out std_logic;
		sram_addr		: out std_logic_vector(18 downto 0);
		sram_data		: in std_logic_vector(15 downto 0)
	);
end top_level;

architecture STR of top_level is
	
	signal rst 				  : std_logic;
	signal pixel_clk          : std_logic;
	signal Hcount             : std_logic_vector(9 downto 0);
	signal Vcount             : std_logic_vector(9 downto 0);
	signal Video_On           : std_logic;
	signal RowAddress         : std_logic_vector(7 downto 0);
	signal ColumnAddress      : std_logic_vector(6 downto 0);
	signal Row_en             : std_logic;
	signal Column_en          : std_logic;
	signal player_num 		  : std_logic;
	signal brick_en 		  : std_logic;
	signal sram_block_sel     : std_logic_vector(3 downto 0);
	signal SRAM_Address       : std_logic_vector(14 downto 0);
	signal q                  : std_logic_vector(15 downto 0);

begin

	rst <= not nrst;

	U_CLKDIV : entity work.clk_div port map(
		clk              => clk,
		rst              => rst,
		pixel_clk        => pixel_clk
	);

	U_VGA_SYNC : entity work.VGA_sync_gen port map(
		clk              => pixel_clk,
		rst              => rst,
		Hcount           => Hcount,
		Vcount           => Vcount, 
		Horiz_sync       => Horiz_sync,
		Vert_sync        => Vert_sync, 
		Video_On         => Video_On
	);

	U_ROWADDRESS : entity work.RowAddressLogic port map(
		Hcount           => Hcount,
		Vcount           => Vcount,
		Video_On         => Video_On,
		RowAddress       => RowAddress,
		Row_en           => Row_en,
		brick_en 		 => brick_en
	);

	U_COLUMNDDRESS : entity work.ColumnAddressLogic port map(
		Hcount           => Hcount,
		Vcount           => Vcount,
		Video_On         => Video_On,
		Player_num 		 => player_num,
		ColumnAddress    => ColumnAddress,
		Column_en        => Column_en
	);

	U_SRAM_BLOCK_SEL_GEN : entity work.sram_block_sel_gen port map(
		Video_On			=> Video_On,
		player_num 			=> player_num,
		game_state			=> game_state,
		brick_en 			=> brick_en,
		l_boxer_state		=> l_boxer_state,
		r_boxer_state		=> r_boxer_state,
		sram_block_sel 		=> sram_block_sel
	);

	U_SRAM : entity work.sram_rd_ctrl port map(
		clk 		=> clk,
		rst 		=> rst,
		go			=> '1',
		r_wn		=> '1',
		addr_in		=> sram_block_sel & SRAM_Address,
		--addr_in		=> "0000" & SRAM_Address,
		data_rd		=> q,
		data_wr 	=> (others => '0'),
		ce_n 		=> ce_n,
		we_n 		=> we_n,
		oe_n		=> oe_n,
		addr 		=> sram_addr,
		io			=> sram_data
	);

	SRAM_Address <= RowAddress & ColumnAddress;

	process(Video_On, Row_en, Column_en, q)
	begin

		if(Video_On = '1' and Row_en = '1' and Column_en = '1') then
			Red        <= q(11 downto 8);
			Green      <= q(7 downto 4);
			Blue       <= q(3 downto 0);
		else
			Red        <= "0000";
			Green      <= "0000";
			Blue       <= "0000";
		end if;

	end process;
end STR;