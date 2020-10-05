<script>
	import Toolbar from './Toolbar.svelte'
	import EditorContainer from './EditorContainer.svelte'
</script>

<main>
	<Toolbar />
	<EditorContainer />
</main>

<style>
	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>